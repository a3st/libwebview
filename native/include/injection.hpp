// Copyright © 2022-2024 Dmitriy Lukovenko. All rights reserved.

#pragma once

namespace libwebview
{
    namespace js
    {
        std::string const onLoadHTMLInjection = R"(
            class Queue {
                constructor() {
                    this.elements = {};
                    this.head = 0;
                    this.tail = 0;
                }

                enqueue(element) {
                    this.elements[this.tail] = element;
                    this.tail++;
                }

                dequeue() {
                    const item = this.elements[this.head];
                    delete this.elements[this.head];
                    this.head++;
                    return item;
                }

                peek() {
                    return this.elements[this.head];
                }

                length() {
                    return this.tail - this.head;
                }

                isEmpty() {
                    return this.length == 0;
                }
            }

            class IndexAllocator {
                constructor(count) {
                    this.queue = new Queue();

                    for(let i = 0; i < count; i++) {
                        this.queue.enqueue(i);
                    }
                }

                allocate() {
                    return this.queue.dequeue();
                }

                deallocate(element) {
                    this.queue.enqueue(element);
                }
            }

            class WebView {
                static MAX_RESULTS = 1000;

                constructor() {
                    this.results = {};
                    this.allocator = new IndexAllocator(WebView.MAX_RESULTS);
                }

                __free_result__(index) {
                    this.allocator.deallocate(index);
                }

                bind(name, func) {
                    document.addEventListener(String.format('webview:{0}', name), func);
                }

                invoke(name, ...args) {
                    const index = this.allocator.allocate();

                    let promise = new Promise((resolve, reject) => {
                            this.results[index] = {
                            resolve: resolve,
                            reject: reject
                        };
                    });

                    window.chrome.webview.postMessage(
                        JSON.stringify({
                            index: index,
                            func: name,
                            args: Array.from(args)
                        })
                    );
                    return promise;
                }
            }

            let webview = new WebView();
        )";

        std::string const onResultResolveInjection = "webview.results[{0}].resolve({1}); webview.__free_result__({0});";

        std::string const onResultRejectInjection = "webview.results[{0}].reject({1}); webview.__free_result__({0});";

        std::string const onEmitInjection =
            "const event = new CustomEvent('{0}', '{1}'); document.dispatchEvent(event);";
    } // namespace js
} // namespace libwebview
import os
import subprocess
import json
import pathlib
import platform
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext

class CMakeExtension(Extension):
    def __init__(self, name):
        super().__init__(name, sources=[])


class CMakeBuildExt(build_ext):
    def build_extension(self, ext: CMakeExtension):
        self.build_temp = os.path.join(os.path.dirname(__file__), 'build')
        os.makedirs(self.build_temp, exist_ok=True)

        project_root = os.path.join(os.path.dirname(__file__), '..', '..', 'native')

        config = 'Debug' if self.debug else 'Release'

        match platform.system():
            case 'Windows':
                platform_type = 'Edge'
                arch_type = 'x86_64'

        cmake_args = [
            '-DCMAKE_BUILD_TYPE=' + config,
            '-DCMAKE_RUNTIME_OUTPUT_DIRECTORY=' + os.path.abspath(os.path.join(self.build_lib, self.distribution.packages[0], 'lib', arch_type)),
            '-B' + os.path.abspath(self.build_temp),
            '-S' + os.path.abspath(project_root),
            '-G Ninja'
        ]
        
        build_args = [
            '--build', os.path.abspath(self.build_temp),
            '--config', config,
            '--target', ext.name + platform_type
        ]

        try:
            output = subprocess.check_output([
                os.path.abspath(os.path.join("C:", "Program Files (x86)", "Microsoft Visual Studio", "Installer", "vswhere.exe")), 
                "-products", "*", 
                "-format", "json", 
                "-utf8", 
                "-prerelease", 
                "-requires", "Microsoft.Component.MSBuild"
            ])

            data = json.loads(output)
            cmd_path = os.path.join(data[0]['installationPath'], "VC", "Auxiliary", "Build", "vcvars64.bat")

        except FileNotFoundError:
            raise RuntimeError("Error: vswhere.exe not found")
        
        subprocess.run([cmd_path, "&", "cmake"] + cmake_args, cwd=self.build_temp)
        subprocess.run([cmd_path, "&", "cmake"] + build_args, cwd=self.build_temp)
        

root_path = pathlib.Path(__file__).parent.resolve()
setup(
    name='libwebview',
    packages=['libwebview'],
    version='1.0.4',
    author="Dmitriy Lukovenko",
    author_email='mludima23@gmail.com',
    description="Library for application development using WebView",
    long_description=(root_path / "README.md").read_text(encoding='utf-8'),
    long_description_content_type='text/markdown',
    license=(root_path / "LICENSE").read_text(encoding='utf-8'),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: MIT License",
        "Operating System :: Android",
        "Operating System :: Microsoft :: Windows",
        "Operating System :: POSIX :: Linux"
    ],
    python_requires=">=3.11",
    project_urls={
        "Documentation": "https://github.com/a3st/libwebview/wiki",
        "Source": "https://github.com/a3st/libwebview"
    },
    ext_modules=[CMakeExtension('WebView')],
    cmdclass={ 'build_ext': CMakeBuildExt },
    include_package_data=True
)
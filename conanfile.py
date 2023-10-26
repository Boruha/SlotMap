from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake
from os import path

class SloptMapRecipe(ConanFile):
    name    = "SloptMap"
    version = "0.1.0"

    # Optional metadata
    license     = "GNU-2.0"
    author      = "Borja Pozo Wals", "borja.pozo@gmail.com"
    url         = "https://github.com/Boruha/SlotMap.git"
    description = "Container that provides direct access to specific element while allows cache friendly iterations."
    topics      = "Container", "STL-like", "dynamic memory"

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options  = {
        "shared": [True, False],
        "fPIC"  : [True, False]
    }
    default_options = {
        "shared": False, 
        "fPIC": True
    }
    generators = "CMakeDeps"

    def requirements(self):
        pass

    def build_requirements(self):
        pass

    def config_options(self):
        if self.settings.os == "Windows":
            self.options.rm_safe("fPIC")

    def configure(self):
        if self.options.shared:
            self.options.rm_safe("fPIC")

    def layout(self):
        self.folders.generators = path.join("build", self.settings.get_safe("os"), "generator")
        self.folders.build = path.join("build", self.settings.get_safe("os"),
                                self.settings.get_safe("arch"), self.settings.get_safe("build_type"))

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package_info(self):
        self.cpp_info.libs = ["SloptMap"]
        self.cpp_info.set_property("cmake_find_mode", "both")

    

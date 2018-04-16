#ifndef OGGY_RESOURCE_MANAGER_HPP
#define OGGY_RESOURCE_MANAGER_HPP

#include <map>
#include <string>
#include <iostream>

namespace oggy {
  template<class Resource>
  class ResourceManager {
  public:
    ResourceManager();
    ~ResourceManager();
    void load(std::string id, Resource resource);
    void unload(std::string id);
    void get(std::string id);

  private:
    std::map<std::string, Resource> resources;
  };

  template<class Resource>
  ResourceManager<Resource>::ResourceManager() {

  }

  template<class Resource>
  ResourceManager<Resource>::~ResourceManager() {
    std::cout << "i die" << std::endl;
    for(auto it = this->resources.begin(); it != this->resources.end(); ++it) {
      std::cout << "fififi" << it->first << std::endl;
      //this->unload(it->first);
    }
  }

  template<class Resource>
  void ResourceManager<Resource>::load(std::string id, Resource resource) {
    this->resources[id] = resource;
  }

  template<class Resource>
  void ResourceManager<Resource>::unload(std::string id) {
    delete this->resources[id];
    this->resources.erase(id);
  }

  template<class Resource>
  void ResourceManager<Resource>::get(std::string id) {
    return this->resources[id];
  }
}

#endif

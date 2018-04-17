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
    void load(std::string id, Resource * resource);
    Resource * get(std::string id);

  private:
    std::map<std::string, Resource *> resources;
  };

  template<class Resource>
  ResourceManager<Resource>::ResourceManager() {

  }

  template<class Resource>
  ResourceManager<Resource>::~ResourceManager() {
    for(auto it = this->resources.begin(); it != this->resources.end(); ++it) {
      delete it->second;
    }
  }

  template<class Resource>
  void ResourceManager<Resource>::load(std::string id, Resource * resource) {
    this->resources[id] = resource;
  }

  template<class Resource>
  Resource * ResourceManager<Resource>::get(std::string id) {
    return this->resources[id];
  }
}

#endif

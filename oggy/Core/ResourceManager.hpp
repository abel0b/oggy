#ifndef OGGY_RESOURCE_MANAGER_HPP
#define OGGY_RESOURCE_MANAGER_HPP

#include <map>
#include <string>

namespace oggy {
  template<class Resource>
  class ResourceManager {
  public:
    ResourceManager();
    ~ResourceManager();
    void load(std::string& id, Resource resource);
    void unload(std::string& id);
    void get(std::string& id);

  private:
    std::map<std::string, Resource> resources;
  };

  template<class Resource>
  ResourceManager<Resource>::ResourceManager() {

  }

  template<class Resource>
  ResourceManager<Resource>::~ResourceManager() {

  }

  template<class Resource>
  void ResourceManager<Resource>::load(std::string& id, Resource resource) {
    this->resources[id] = resource;
  }

  template<class Resource>
  void ResourceManager<Resource>::unload(std::string& id) {
    this->resources.erase(id);
  }

  template<class Resource>
  void ResourceManager<Resource>::get(std::string& id) {
    return this->resources[id];
  }
}

#endif

#include <mbgl/style/layer_impl.hpp>

namespace mbgl {
namespace style {

std::unique_ptr<Layer> Layer::Impl::copy(const std::string& id_,
                                         const std::string& ref_,
                                         const std::string& source_) const {
    std::unique_ptr<Layer> result = clone();
    result->baseImpl->id = id_;
    result->baseImpl->ref = ref_;
    result->baseImpl->source = source_;
    return result;
}

const std::string& Layer::Impl::bucketName() const {
    return ref.empty() ? id : ref;
}

bool Layer::Impl::hasRenderPass(RenderPass pass) const {
    return bool(passes & pass);
}

bool Layer::Impl::needsRendering() const {
    return passes != RenderPass::None && visibility != VisibilityType::None;
}

} // namespace style
} // namespace mbgl

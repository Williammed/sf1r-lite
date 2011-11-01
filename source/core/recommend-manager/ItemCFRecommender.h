/**
 * @file ItemCFRecommender.h
 * @brief recommend items using item-based Collaborative Filtering algorithm
 * @author Jun Jiang
 * @date 2011-10-14
 */

#ifndef ITEM_CF_RECOMMENDER_H
#define ITEM_CF_RECOMMENDER_H

#include "Recommender.h"
#include "RecTypes.h"

#include <vector>
#include <map>
#include <string>

namespace sf1r
{

class ItemCFRecommender : public Recommender
{
public:
    ItemCFRecommender(
        ItemManager& itemManager,
        ItemCFManager& itemCFManager
    );

protected:
    virtual bool recommendImpl_(
        RecommendParam& param,
        ItemFilter& filter,
        std::vector<RecommendItem>& recItemVec
    );

    typedef ItemCFManager::ItemWeightMap ItemWeightMap;
    bool recommendFromItemWeight_(
        int limit,
        const ItemWeightMap& itemWeightMap,
        ItemFilter& filter,
        std::vector<RecommendItem>& recItemVec
    );

    void setReasonEvent_(
        std::vector<RecommendItem>& recItemVec,
        const std::string& eventName
    ) const;

protected:
    ItemCFManager& itemCFManager_;
};

} // namespace sf1r

#endif // ITEM_CF_RECOMMENDER_H

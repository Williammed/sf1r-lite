///
/// @file MiningQueryLogHandler.hpp
/// @brief
/// @author Jia Guo <guojia@gmail.com>
/// @date Created 2010-05-13
/// @date Updated 2010-05-13
///

#ifndef MININGQUERYLOGHANDLER_HPP_
#define MININGQUERYLOGHANDLER_HPP_

#include <common/SFLogger.h>
#include <log-manager/LogManager.h>
#include <string>
#include <vector>
#include <set>
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>

#include <boost/function.hpp>
#include <common/type_defs.h>
#include "query-recommend-submanager/RecommendManager.h"
#include <configuration-manager/MiningConfig.h>
#include "query-correction-submanager/QueryCorrectionSubmanager.h"
#include <util/singleton.h>
#include <util/cronexpression.h>
namespace sf1r
{

class MiningQueryLogHandler : public boost::noncopyable
{
    typedef izenelib::am::SSFType<uint32_t, std::pair<izenelib::util::UString, uint32_t> , uint32_t, false> TimedQueryLogSSFType;

    typedef std::map<std::string, boost::shared_ptr<RecommendManager> >::iterator map_it_type;
public:

    /*MiningQueryLogHandler(const boost::shared_ptr<MiningManagerConfig>& miningConfig,
    const std::string& collectionName, LogManager* pLogManager,
    const boost::shared_ptr<RecommendManager>& recommendManager,
    const std::string& workingPath)*/
    ;
    static MiningQueryLogHandler* getInstance()
    {
        return izenelib::util::Singleton<MiningQueryLogHandler>::get();
    }

public:

    void SetParam(uint32_t wait_sec, uint32_t days);

    MiningQueryLogHandler();

    ~MiningQueryLogHandler();

    void addCollection(const std::string& name, const boost::shared_ptr<RecommendManager>& recommendManager);

    bool cronStart(const std::string& cron_job);

    void runEvents();

private:
    void cronJob_();

    void processAutofill_(const boost::posix_time::ptime& nowTime);





private:
    std::map<std::string, boost::shared_ptr<RecommendManager> > recommendManagerList_;
    std::set<std::string> collectionSet_;
    uint32_t waitSec_;
    uint32_t days_;
    izenelib::util::CronExpression cron_expression_;
    boost::mutex mtx_;

};


}
#endif
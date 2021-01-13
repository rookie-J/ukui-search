#ifndef LIBSEARCH_H
#define LIBSEARCH_H

#include "libsearch_global.h"
#include "index/file-searcher.h"
#include "appsearch/app-match.h"
#include "settingsearch/setting-match.h"
#include "file-utils.h"
#include "global-settings.h"
#include "index/first-index.h"

#include "index/ukui-search-qdbus.h"
#include "index/inotify-index.h"

class  LIBSEARCH_EXPORT GlobalSearch
{
public:

    static QStringList fileSearch(QString keyword, int begin = 0, int num = -1);

private:
    GlobalSearch();
};

#endif // LIBSEARCH_H

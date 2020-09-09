#ifndef CONFIGDATA_H
#define CONFIGDATA_H

#include <wx/stdpaths.h>
#include <wx/config.h>
#include <wx/confbase.h>
#include <wx/fileconf.h>

class ConfigData
{
    public:
        ConfigData();
        virtual ~ConfigData();

         wxString basisFunktion;

    protected:

    private:



};

#endif // CONFIGDATA_H

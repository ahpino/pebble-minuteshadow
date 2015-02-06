#include <pebble.h>
#include "configuration.h"

bool g_HorizontalShadow = true;

void InitConfiguration()
{
    if (!persist_exists(HORIZONTAL_SHADOW)) {
        g_HorizontalShadow = true;
    }
    else {
        g_HorizontalShadow = persist_read_bool(HORIZONTAL_SHADOW);
    }

    app_message_register_inbox_received((AppMessageInboxReceived) ConfigurationHandler);
    app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());
}

void ConfigurationHandler(DictionaryIterator* a_Iterator, void* a_Ctx)
{
    Tuple* t = dict_read_first(a_Iterator);

    if(t) {
        switch(t->key) {
            case HORIZONTAL_SHADOW:
                if(strcmp(t->value->cstring, "horizontal") == 0) {
                    persist_write_bool(HORIZONTAL_SHADOW, true);
                    g_HorizontalShadow = true;
                }
                else if(strcmp(t->value->cstring, "vertical") == 0) {
                    persist_write_bool(HORIZONTAL_SHADOW, false);
                    g_HorizontalShadow = false;
                }
                break;
            default:
                break;
        }
    }
}

bool IsShadowHorizontal()
{
    return g_HorizontalShadow;
}

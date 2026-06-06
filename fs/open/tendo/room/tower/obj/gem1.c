//白玉
#include <command.h>
inherit ITEM;

void create()
{
        set_name("白玉", ({ "gem" }));
        set_weight(30000);
        if( clonep() )
          set_default_object(__FILE__);
        else
        {
          set("unit", "塊");
          set("long",@LONG
        這是一塊雪白的白玉!!你可以將它拿去給冶鑄的大師, 
        白玉做成的武器或是防具都是不錯的!!
LONG);
          set("value", 800);
          set("material", "gem");
          set("no_sell", 1);
          set("no_auc", 1);
        }
}




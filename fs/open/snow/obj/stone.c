inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIC + "天邪石" + NOR,({"stone"}));
    set("long","一顆奇怪的石頭，是現任掌門劉全書的父親所傳下之傳家之寶，十分珍貴。\n");
    set("unit","顆");
    set("quest_stone",1);
     set("value",10000);
     set("no_sell",1);
        setup();
}

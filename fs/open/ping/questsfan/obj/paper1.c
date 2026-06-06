inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIW "飄陽的傳說" NOR,({"story paper","paper"}));
        set("long","這是一張由秦厲害那買來的情報，你可以用(read)來觀看。\n");
        set("unit","張");
set("no_get", 1);
set("no_auc",1);
set("no_put",1);
set("no_give", 1);
set("value",10000000);
        setup();
}
void init()
{
        add_action("do_read","read");
}
int do_read( string arg )
{
       object me = this_player();
       int level=(int)(me->query_skill("literate",1));
       if(level >= 90 )
       {
       me->set_temp("buy_ok",1);
       cat( sprintf(__DIR__"paper1") );
       return 1;
       }
       else
       tell_object(me,"你左看右看就是看不懂這張的內容，看來要再去進修進修囉!!!\n");
       return 1;
}


inherit ITEM;
#include <ansi.h>
inherit F_AUTOLOAD;
void create()
{
                set_name(HIC + "風雷符" + NOR, ({ "wind token","token",}) ); 
                set_weight(50);
                set("long",
 "這是由聖光祝福過的聖符,只有擁有這的人才可到幫派所在地,
據說此信物具有瞬間送人至遠方的能力(magic light)....\n"

);
                if( clonep() )
                        set_default_object(__FILE__);
                else {
                        set("unit", "件");
                        set("value", 0);
                        set("no_drop",1);
                        set("no_insert",1);
                        set("no_auc", 1);
      set("nickname",HIC + "風雷幫" + HIC + "火爆浪子" + NOR);
                }
}

void init()
{
      add_action("do_magic", "magic");
}
int do_magic(string str)
{
        object me;
        me = this_player();

        if(!str || str != "light")
            return notify_fail("你在作什麼啊 ?\n");
          message_vision( 
sprintf("一道" + HIC + "聖光" + NOR + "將$N傳送到幫派的所在地。\n"), this_player() );
        me->move("/open/clam/wind.c");
        message_vision( 
sprintf("天空出現一道" + HIC + "雷光" + NOR + ",只見$N飛來了這裡。\n"),this_player());
        return 1;
}
int query_autoload()
{
        return 1;
}

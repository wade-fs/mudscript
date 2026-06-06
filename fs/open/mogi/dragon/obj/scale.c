//by Casey

inherit ITEM;
#include <ansi.h>
inherit F_AUTOLOAD;
void create()
{
                set_name(HIY + "魔龍鱗" + NOR, ({ "dragon scale","scale",}) ); 
                set_weight(50);
                set("long",
 "黃金甲龍身上的鱗片 ,具有特殊的魔力
拿來使用可以將人瞬間傳送到魔界(use scale),查看剩下次數(show scale).\n "

);
                if( clonep() )
                        set_default_object(__FILE__);
                else {
                        set("unit", "片");
                        set("value", 5000);
                        set("no_insert",1);
                        set("no_auc", 1);
                        set("no_sell",1);
                        set("no_out",1);


                }
}

void init()
{
      add_action("do_magic", "use");
      add_action("do_show", "show");
}
int do_magic(string str)
{
         object me,ob;
        me = this_player();

        if(!str || str != "scale")
            return notify_fail("你在作什麼啊 ?\n");
      if( !objectp(ob = present(str,me)) )
    return notify_fail("你身上沒有這樣東西。\n");
	if( me->is_fighting() )
                return notify_fail("戰鬥中不能使用喔。\n");
if( environment(me)->query("no_scale") )
return notify_fail("在這不能用。\n");
if(me->query("ghost")==1)
return notify_fail("鬼魂沒資格使用魔龍鱗。\n");
          message_vision( 
sprintf("一片" + HIY + "光幕" + NOR + "慢慢將$N籠罩住 ,傳送回魔界的村莊。\n"), this_player() );

        me->move("/open/mogi/village/room/room-05.c");
        message_vision( 
sprintf("天邊出現一道" + HIY + "閃光" + NOR + ",只見$N飛來了這裡。\n"),this_player());
   if(me->query_temp("use_scale_number") > 1)
     me->add_temp("use_scale_number",-1);
   else {
     write("\n" + HIY + "魔龍鱗" + NOR + "因法力耗盡而崩散成粉末。\n");
     destruct(ob);
     return 1;
   }
        return 1;
}
int do_show(string str)
{
        object me,ob;
        int number;
        me = this_player();

        if(!str || str != "scale")
            return notify_fail("你在做什麼啊 ?\n");
      if( !objectp(ob = present(str,me)) )
    return notify_fail("你身上沒有這樣東西。\n");
   number = me->query_temp("use_scale_number");
   printf("\n魔龍鱗還能再使用 %d 次\n",number);
   return 1;
}


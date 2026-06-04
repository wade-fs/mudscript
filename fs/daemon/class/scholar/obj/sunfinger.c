// made by onion
#include <ansi.h>
#include <weapon.h>
inherit STABBER;
void create()
{
        set_name("一陽氣指",({"sunforce finger","finger"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","以純正內家罡\氣化成的氣指, 可由顏色來辨識威力的大小
可以鍊化(addin)進入段家的武器「飄陽扇」中，以在戰鬥中作為致勝的利器。\n");
        set("unit","束");
        set("value", 0);
        set("material","force");
        set("no_drop",1);
 //       set("wield_msg","$N將$n從手指尖端激出, 幻化成一束光芒。\n");
        set("unwield_msg","$N將$n斂入手指內, 一點光芒消逝於指尖。\n");
        }
        init_stabber(1);
        setup();
}
void init()
{
        add_action("do_wield","wield");
//指令簡化的結果，害我的action要特多
        add_action("do_wield","wi");
        add_action("do_wield","wie");
        add_action("do_wield","wiel");
        add_action("do_vanish","vanish");
        add_action("do_sp","addin");    //新增功能，經解迷可以鍊化入飄陽扇
}
int do_wield(string arg)
{
        object me=this_player();
        object ob=this_object();

        if(!arg) return 1;
        if(arg!="all" && arg!="finger" && arg!="sunforce finger")
                return 1;

        if(me->query("family/family_name")!="段家")
        {
        message_vision("$N緩緩以內力運功\, 而$n便神奇的自$N手上消失無蹤。\n",me,ob);
        destruct(ob);
        }
        else
        {
        ::wield();
        message_vision("$N將$n從手指尖端激出, 幻化成一束光芒。\n",me,ob);
        }
        return 1;
}

int do_vanish(string str)
{
        object me=this_player();
        object ob=this_object();
        message_vision("$N緩緩以內力運功\, 而$n便神奇的自$N手上消失無蹤。\n",me,ob);
        me->add("force",1);
        destruct(ob);
        return 1;
}
int do_sp(string str)
{
        object me=this_player();
        object ob=this_object();
        int fun;

        if(!me->query("marks/fan-finger"))
                return 0;

        if(!str || str!="fan")
                return notify_fail(HIC + "你要把一陽指氣鍊化到那裡去阿??\n" + NOR);

        if(!present("finger fan",me))
                return notify_fail(HIC + "你的手中沒有飄陽扇，再怎麼鍊化下去也沒用!!\n" + NOR);

        if(me->is_fighting())
                return notify_fail(HIG + "戰鬥中是無法將一陽指氣進行鍊化的!!\n" + NOR);

        fun=me->query("functions/fan-finger/level");
        switch(fun){
          case 0..10:
            fun=10;
            break;
          case 11..20:
            fun=20;
            break;
          case 21..30:
            fun=30;
            break;
          case 31..40:
            fun=40;
            break;
          case 41..50:
            fun=50;
            break;
          case 51..60:
            fun=60;
            break;
          case 61..70:
            fun=70;
            break;
          case 71..80:
            fun=80;
            break;
          case 81..90:
            fun=90;
            break;
          case 91..100:
            fun=100;
            break;
          case 101..110:
            fun=110;
            break;
          case 111..120:
            fun=120;
            break;
        }
        if(me->query_temp("fan-finger") >= fun)
          return notify_fail(HIM + "你一次只可以鍊化"+CHINESE_D->chinese_number(fun)+"束一陽指氣進入飄陽扇中。\n" + NOR);

        if(query("equipped"))
                return notify_fail(HIY + "你現在正裝備著一陽指氣，所以無法將其鍊化。\n" + NOR);

        message_vision(HIC + "
$N" + HIC + "將真氣聚於手上，臉上的顏色由紅轉白，又由白轉紅，全身汗流夾背，
$N" + HIC + "忽然間眼放精光，手指竄出一道指氣流入了飄陽扇中!!!\n

" + HIR + "$N" + HIR + "因為用勁過度，暫時無法行動。\n" + NOR,me);

        me->start_busy(2);
        me->add_temp("fan-finger",fun/10);
        me->add("force",-100);
        me->set_temp("block_msg/all",1);
        call_out("delay",3,ob,me);
        return 1;
}
int delay(object ob,object me)
{
        me->set_temp("block_msg/all",0);
        destruct(ob);
        return 1;
}

#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
int do_list();
void create() {
set("short",CYN"專門座騎集散中心"NOR);
set("long",@LONG

這裡是傳說中的專門座騎發散中心。只有傳說中的大俠方能在這裏
取得專門的座騎。座上這些座騎將可以使你的戰鬥力大為提升至極
高境界。你可以使用(list)查看這裡有那一些大俠可以取得座騎!!

LONG);
        set("exits",([ /* sizeof() == 1 */
            "west" : "/open/port/room/r2-2",
      ]));
        set("light_up", 1);
        set("no_kill", 1);
        set("no_fight", 1);
        set("no_magic", 1);
        setup();
}

void init() {
        add_action("do_list","list");
        add_action("do_get_horse","get_horse");

}

int do_list() {
        return notify_fail("
                 大俠名稱                    座騎名稱
       ----------------------------------------------------------
                 crythree                    紫雲幻龍
                 ddt                         超級壞馬
                 dunga                       九天仙龍
                 hikki                       八焚殺魔
                 killer                      天誅神獸
                 leon                        殺人兇馬
                 lovesui                     風殘雪影
                 ollie                       赤血妖龍
                 rry                         人間兇獸
                 sdgudam                      嘯天犬
                 smirk                       熾熱炎獸
                 victor                       征服者
       ---------------------------------------------------------

           您只需下 get_horse 即可叫來您的座騎，謝謝您的光臨！\n\n");
}
int do_get_horse() {
        object me = this_player(),mid;
        string name=me->query("id");
        if(me->query_temp("get_net_horse"))
         return notify_fail("一次上線只能領一次自己的座騎了!!!。\n");
        switch(name) {
           case "crythree"    :
              mid = new("/nets/horse/crythree");
                break;
           case "ddt"    :
              mid = new("/nets/horse/ddt");
                break;
           case "dunga"    :
              mid = new("/nets/horse/dunga");
                break;
           case "hikki"     :
              mid = new("/nets/horse/hikki");
              break;
           case "killer"   :
              mid = new("/nets/horse/killer");
              break;
           case "leon"  :
              mid = new("/nets/horse/leon");
              break;
           case "lovesui"  :
              mid = new("/nets/horse/lovesui");
              break;
           case "ollie"     :
              mid = new("/nets/horse/ollie");
              break;
           case "rry"  :
              mid = new("/nets/horse/rry");
              break;
           case "sdgudam"  :
              mid = new("/nets/horse/sdgudam");
              break;
           case "smirk" :
              mid = new("/nets/horse/smirk");
              break;
           case "victor" :
              mid = new("/nets/horse/victor");
default : return notify_fail(HIY
"對不起!!!您不是傳說中的大俠,因此沒有專屬的座騎!!\n"NOR);
        }
        mid->move(environment(me));
        mid->set_leader(me);
        me->set_temp("get_net_horse", 1);
        message_vision(HIW"一道白光降下!!$N的專屬座騎出現在$N之前！\n"NOR,me);
     log_file("net/horse", sprintf("%s(%s) 領取專屬座騎!!時間是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
}


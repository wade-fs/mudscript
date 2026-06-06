#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
int do_list();
void create() {
set ("short",HIG + "網聚獎品『玩家防具』發放處" + NOR);
set ("long","這次網聚共有將近七十位玩家參加!!!!
網聚的獎品單請打help fs_net及help fs_net2
此房間是用來發放玩家防具的房間
東邊的房間是發放替身的房間!!!
指令如下：
          get_myeq  <領取這次網聚的獎品>

請注意：玩家EQ限領一套!!!且不能給其他人.....
若因系統設定造成EQ不見,請POST.將花一星期時間檢查後!!
方會補發!!!!
");
  set("no_kill",1);
  set("no_fight",1);
  set("light_up",1);
  set("exits", ([
  "north" : "/open/wiz/godroom",
  ]));

}

void init() {
        add_action("do_get_myeq","get_myeq");

}
int do_get_myeq() {
        object me = this_player(),mid,lanc;
        string name=me->query("id");
        if(me->query("fs_net3/myeq"))
         return notify_fail("你以經領了.....!!\n");
        switch(name) {
           case "lancelin"    :
              mid = new("/autoload/player-eq/lancelin");
              lanc = new("/autoload/player-eq/lancelin-weapon");
                break;
           case "aspire"    :
              mid = new("/autoload/player-eq/aspire");
                break;
           case "zero"    :
              mid = new("/autoload/player-eq/zero");
                break;
           case "amy"     :
              mid = new("/autoload/player-eq/amy");
              break;
           case "pnx"   :
              mid = new("/autoload/player-eq/pnx");
              break;
default : return notify_fail(HIY
"對不起!!!您不在名單之上!!\n" + NOR);
        }
        mid->move(me);
        me->set("fs_net3/myeq", 1);
        write("恭喜你拿到自我命名天界型的防具!!!\n");
        write("由於時間拖太久了.所以補發三個替身給各位!!\n");
//        me->add("standby",3);
        if (name == "lancelin")
         lanc->move(me);
     log_file("net/myeq", sprintf("%s(%s) 領取專屬座騎!!時間是%s!!\n"
     ,me->query("name"),me->query("id"),ctime(time()) ));
}


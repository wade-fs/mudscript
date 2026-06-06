// room7.c by roger
inherit ROOM;
#include <ansi.h>
void create () {
set ("short", "古堡三樓");
	set( "build", 11 );
        set ("long","牆壁上點著青綠色的鬼火，仔細一看是由酷似骷髏\的銀器作成燈座，綠
光便由骷髏\的兩隻眼睛裡射出，豪華中透著恐怖的氣息。地上也鋪著厚
厚的地毯，令人不禁驚奇地東張西望。四周的妖魔似乎也都披金戴銀，
性情也溫和的多，但一身武藝看起來比樓下的是有過之而無不及，你不
禁懷疑自己真是在魔界？但這裡卻有一扇大門，寫著" + HIW + "『白虎室』。
" + NOR);

        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 1 */
            
        "west" : __DIR__"room43",   
            
      ]));
        set("objects",([ /* sizeof() == 1 */
   __DIR__"npc/tiger-guard.c" : 1,
      ]));

        setup();
}
void init()
{
        add_action("do_unlock", "unlock");
}

int do_unlock(string str){
   object me,obj;
   object key;
   string tigerkey;
   me = this_player();
   
        if(!str || str != "door with tigerkey"){
                return notify_fail("你想開什麼？\n");
                return 0;
                                 }
        else{
        if(present("tigerkey",me)){
          if(present("guard",environment(me))){
           message_vision(HIY + "白虎守衛瞪了你一眼\n" + NOR,me);
           return 0;
                                            }              
        message_vision(HIC + "$N用白虎之鑰打開白虎密室\n" + NOR,me);                                
            set("exits/enter",__DIR__"room45");
                  set_temp("have_open",1);
        if (!key) key = present("tigerkey", me);
        if (!key) key = present("tigerkey", environment(me));
        if (!key) key = find_object( resolve_path(me->query("cwd"), tigerkey) );
                  destruct(key);
                  remove_call_out("do_closed");
                  call_out("do_closed",15);
                  return 1;
                                  }
        else write("你沒有這東西\n");
           }
}
void do_closed()
{
        delete_temp("have_open");
        delete("exits/enter");
        tell_room(this_object(),"大門碰的一聲又關起來。\n");
}

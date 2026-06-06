
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "鎖妖塔一樓--");
  set ("long", @LONG
這兒是鎖妖塔的一樓正廳，你發覺這兒空蕩蕩的，什麼都沒有，唯一你感覺得到
的是那一陣陣的妖氣。你看到的大廳的中樑上懸著一個牌匾(tablet)。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"road4",
  "north" : __DIR__"tower1-2",
]));
set("objects", ([ /* sizeof() == 2 */
"/open/tendo/room/tower/npc/genies.c" : 2,
]));

        set("no_transmit",1);
  set("light_up", 1);
  set("item_desc", ([ /* sizeof() == 2 */
  "tablet" : @LONG
         牌匾上寫著四個大字  --  「鎖妖塔」 -- 
              不遵約祭祀或誤時者殺 !
              衣冠不整執禮不恭者殺 !
              言行倨傲存心不虔者殺 !
              胸懷詭謀偷襲暗算者殺 !
              擅入塔內陰謀不軌者殺 !
              以眾擊寡乘人之危者殺 !
              橫蠻跋扈黷武好鬥者殺 !

                             
LONG,
 ]));
  setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="out" )
        message("system",
 HIW + "\n\t武林之中傳來一道消息 : 非常遺憾～" + HIY + ""+this_player()->name()+"" + HIW + "因膽怯而退出了" + HIR + "鎖妖塔" + HIW + " !!\n" + NOR,users());
        return ::valid_leave(me, dir);
}
void init()
{
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;
      call_out( "fire_wound", 6,previous_object());
}

void fire_wound(object ob)
{
        if( !ob || !present(ob) ) return;
       tell_object(ob,HIR + "～鬼影幢幢～你覺得胸中一陣翻滾，忽然一道血箭從你的嘴裡噴了出來。\n" + NOR);
       ob->add("kee",-100);
       call_out("fire_wound", 6,ob);
}


void reset()
{
        ::reset();
        delete("go_north");
}





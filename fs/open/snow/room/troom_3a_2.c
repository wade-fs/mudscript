// Room: /u/e/eiei/room/troom_3a_2.c
inherit ROOM;

string search();
void create ()
{
  set ("short", "殘破青石路");
  set ("long", @LONG
    走到這裡，樹林似乎更冒密了。不過如果你仔細看
    的話，在路的一旁好像有一條青石板鋪成的的小路，雖
    然看起來青石板已經有點老舊，不過由於青石板一直向
    樹林裡面延伸，所以看起來就顯的有一點突出了。
LONG);

  set("outdoors", "/u/e/eiei/room");
  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"troom_3a_1.c",
]));

 set("search_desc", ([ /* sizeof() == 1 */
  "青石板" : (: search :),
]));
setup();
}
string search()
{
if (this_player()->query_temp("shaswordtime")==1)
{
   message_vision("$N在青石版中找來找去 , 摸出了一顆水法珠並收進口帶中 \n",this_player() );
   this_player()->set_temp("quests/findball3",1);
   new("/open/gsword/obj1/waterball")->move(this_player());
   return "";
  }
        message_vision("$N在這翻來覆去 , 結果什麼也沒發現 \n",this_player());
        return "";
}

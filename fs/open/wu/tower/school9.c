// Room: /u/d/devils/school9.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "夢居");
  set ("long", @LONG
這是任正晴的寢室，擺設十分簡單，只有一張床和一些簡單家俱，
看似單純，卻暗藏玄機，聽說任正晴為了怕人趁他睡覺偷襲他，暗藏了
許多機關，沒事別亂闖這裡，免的死於非命！
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "door" : "\n    一個很不容易被發現的暗門，你可以試著推推看(push)，搞不好可以推開。\n",
]));


  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"school8",
]));

  set("light_up", 1);
  setup();
}

void init() {
   add_action("do_push","push");
   add_action("do_search","search");

}
int do_push(string str) {
     if(!str){
        return notify_fail("你要推什麼東東？？\n");
        }
      else if(str != "door"){
        tell_object(this_player(),HIR + "\n咻～～～ 迎面射來三把飛刀！\n" + NOR);
        tell_object(this_player(),"\n\n不過這機關似乎無意傷人，你很從容地就躲過了。\n");
        return 1;}
     else {
        tell_object(this_player(),"哎呀～～～\n\n你只覺手推了個空，身子便往牆後一跌。\n");
        this_player()->move(__DIR__"road1");
        return 1;}
}

int do_search(string str) {
     if(str == "here"){
        tell_object(this_player(),"你覺得東邊的牆角(corner)有些奇怪，似乎有什麼東西。\n");
        return 1;}
      else if(str != "corner"){
        tell_object(this_player(),"你到底要找什麼東西啊！？\n");
        return 1;}
     else {
        tell_object(this_player(),"你發現東邊的牆似乎有鬆動過的痕跡。你猜想可能有一道暗門(door)。\n");
        return 1;}
}


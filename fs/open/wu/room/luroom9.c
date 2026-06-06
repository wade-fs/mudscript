// Room: /open/wu/room/luroom9.c
// 瀧山武館的練武場
inherit ROOM;
string search();
void create ()
{
  set ("short", "練武場");
  set ("long", @LONG
這裡是瀧山派練武場地的中庭,一條由花崗石所鋪成的道路向瀧山派的
大廳而去,西邊直行的話是通往瀧山派的大門,你忽然發覺花崗石上有
許多的腳痕,看來在此練武的弟子其武學程度以經到達爐火純青的地步
了。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"luroom8",
  "west" : __DIR__"luroom6",
  "south" : __DIR__"luroom10",
  "east" : __DIR__"luroom17",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/wu/npc/e_trainee" : 2,
]));

 set("search_desc", ([ /* sizeof() == 1 */
  "花崗石" : (: search :),
]));
  setup();
}
string search()
{
if (this_player()->query_temp("shaswordtime")==1)
{
   message_vision("$N在花崗石中找來找去 , 摸出了一顆火法珠並收進口帶中 \n",this_player() );
   this_player()->set_temp("quests/findball2",1);
   new("/open/gsword/obj1/fireball")->move(this_player());
   return "";
  }
        message_vision("$N在這翻來覆去 , 結果什麼也沒發現 \n",this_player());
        return "";
}

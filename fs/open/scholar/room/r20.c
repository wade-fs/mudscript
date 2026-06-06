// /u/j/judd/room/r20.c
inherit ROOM;
string search();

void create ()
{
  set ("short", "中堂");
  set ("long", @LONG
這裡是儒門的中堂大廳，兩旁掛滿了各式各樣的筆，牆上則有幾
幅山水畫，閃爍的燭光，更襯托出儒門的氣氛，但也因此看不出兩旁
通往何處，只知道前方就是聖賢書的住處。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"in.c",
  "north" : __DIR__"r17.c",
  "west" : __DIR__"w1.c",
  "east" : __DIR__"e1.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/start/obj/bamboo_pen" : 2,
]));
  set("light_up", 1);

 set("search_desc", ([ /* sizeof() == 1 */
  "山水畫" : (: search :),
]));
 setup();
}
string search()
{
if (this_player()->query_temp("shaswordtime")==1)
{
   message_vision("$N在山水畫中找來找去 , 摸出了一顆木法珠並收進口帶中 \n",this_player() );
   this_player()->set_temp("quests/findball4",1);
   new("/open/gsword/obj1/woodball")->move(this_player());
   return "";
  }
        message_vision("$N在這翻來覆去 , 結果什麼也沒發現 \n",this_player());
        return "";
}

// Room: /open/ping/room/m13.c ~night~(小戀)

inherit ROOM;

void create ()
{
  set ("short", "風行森林外");
	set( "build", 24 );
  set ("long", @LONG

呼～好不容易經過了風行森林,你深深的吸了一口氣,這裡的空氣比森林裡面好多了,聳立在
你眼前的正是風林山,聽說山上有一些殺人不眨眼的山賊,沒事就跑下山來找樂子,當然倒楣
的就是這附近的百姓了. 看來,好像沒有路可以上去風行山,總不可能用爬的吧!我們又不是
烏龜...... 這時候你發現旁邊的岩石好像怪怪的耶～～   嗯～～


LONG);

  set("objects", ([ /* sizeof() == 1 */
]));

  set("outdoors", "/open/ping");

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"m12",
]));

  setup();
}
void init()
{
      add_action("do_search","search");
      add_action("do_push","push");
}
int do_search(string str)
{
      if(str!="stone")
          write(
          "你發現左邊有個大石頭(stone),看起來似乎被人搬動過 !\n");
      else
          write(
          "嗯 ～   以我的力量應該推的動這顆大石頭吧 ！\n");
          return 1;
}
int do_push(string str)
{
          write(
          "你費盡了九牛二虎之力把這個石頭給推開，走入地道中 .....\n",this_player());
          this_player()->move(__DIR__"m14");
          return 1;
}

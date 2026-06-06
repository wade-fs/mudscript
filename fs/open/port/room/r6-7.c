// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","瞭望台底層");
  set ("long", @LONG
這裡是瞭望台的底層 , 城牆到此也到了盡頭 . 瞭望台是個
圓形的建築物 , 據說是由一個外國建築師所設計的 , 乃楓林港
最醒目的地標之一 . 階梯沿著牆壁周圍往上爬昇 , 剛好繞了個
圓圈 . 上面就是瞭望台了 .

LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
	"west" : "/open/port/room/r6-6",
	"up" : "/open/port/room/r6-8",
]));
	set("objects",([
	]));

  setup();
}

// Room: /open/gblade/port/room/p1-1.c
inherit ROOM;

void create ()
{
	set("short","瞭望臺頂");
	set( "build", 21 );
  set ("long", @LONG
登上了瞭望台 , 視野異常遼闊 , 往南方望去 , 整個城市盡
收眼底 . 楓林除了面臨海洋外 , 東西兩面分別連著棲凰嶺和六
陽山 , 北邊隔著城牆與平原相接 . 整個楓林港則猶如一個大工
地 , 到處興建中的房舍 , 道路 , 讓你又一次的體驗到這裡的
生命力 . 如果說新京是個壯年人 , 蜀中就是個白髮蒼蒼的老年
人 , 而楓林則像個精力旺盛的青少年 , 正準備在自己的人生舞
臺上大放異彩 .

LONG);

  set("light_up", 1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 2 */
	"down" : "/open/port/room/r6-7",
]));
	set("objects",([
	"/open/port/npc/guard3":2,
	"/open/port/npc/vice-leader":1,
	]));

  setup();
}

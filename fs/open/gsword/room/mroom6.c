// Room: /d/oldpine/epath2.c

inherit ROOM;

void create ()
{
  set ("short", "蜀山奇陣");
  set ("long", @LONG
    風,在此停了,空氣裡帶著一絲寒意的寂靜,一層淡淡的霧隨地四散,
一株古松(pine)拔地而起,迎向蒼藍的天空,你聽到有人在遠方吟詩,
    詩曰:
       
       蜀山奇陣列山隈,颼颼寒意撲面催,  片片祥光籠斗怲,紛紛淡霧透靈台,
       魚龍此際分真偽,玉石從此盡脫胎,  多少修持遭此劫,三屍斬去五雲開.
        
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "pine" : "你發現古松上有人刻字:
蜀山奇陣奇中奇,五行相剋變化千.
仙劍弟子隨意過,長笑一聲躍(fly up)龍門.
",
]));

  set("light_up", 1);
  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/gsword/room/mroom7.c",
  "east" : "/open/gsword/room/lake0.c",
]));

  setup();
}

void init()
{
	add_action("fly_up","fly");
}

int fly_up(string arg)
{
	if(arg!="up" ){
		return 0;}
	message_vision("一片祥光中隴罩著$N....\n",
		this_player());
	if((string)this_player()->query("family/family_name") == "仙劍派" ) {
		message_vision("\n只見到一陣煙霧,$N消失在祥光中...\n", this_player());
                this_player()->move(__DIR__"test");
	} else {
		message_vision("\n只見一陣煙霧,一顆雞蛋掉在$N的頭上....\n",
			this_player() );
	}
	return 1;
}


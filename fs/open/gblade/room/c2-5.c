inherit ROOM;

void create ()
{
  set ("short", "地道");
  set ("long", @LONG

這裡已經是地道的深處，空氣因為長久沒有流通，味道相當的難聞，在這
個地方待久了，胸口覺得悶悶的，頭也有點不舒服，還是快一點離開免得
暈倒在這個地方。地上躺著幾具屍體 , 其中一具屍體旁寫著幾個殷紅大
字(words) , 似乎是他臨死前所寫 !

LONG);

set("item_desc",
	(["words" : "年輕人 ,能看到這些字 , 即為有緣人 , 我要勸你一句話 :
再往前走 , 你的下場就跟我們一樣 !!

						追風神劍 莊秋鴻 血筆
",]));
  set("light_up",0);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"c2-6.c",
  "south" : __DIR__"c2-4.c",
]));

  setup();
}

// made by funkcat, copy and re-edit by rence
//open/prayer/room/westarea/r1-16.c 
inherit BANK;
void create ()
{
        set("short","林家錢莊");
  set ("long", @LONG
	這家錢莊的老闆是中原遷居到此陳員外的表親, 他在西域的
	地產很多, 所以信用額度很高. 你可以看看這兒的公告
	 (board), 了解一下這裡有些甚麼服務.

LONG);

  set("exits", ([ /* sizeof() == 1 */
        "south" : __DIR__"road20",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "board" : "
    balance: 查看您現有的存款    convert: 換錢幣
    withdraw: 提款               deposit: 存款
 ",
]));
set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
]));

  setup();
}

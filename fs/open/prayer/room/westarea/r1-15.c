// made by funkcat, copy and re-edit by rence
//open/prayer/room/westarea/r1-15.c 
inherit BANK;
void create ()
{
        set("short","陳家錢莊");
  set ("long", @LONG
	這裡是西域裡規模龐大的錢莊, 而且西域的錢莊老闆都是親戚
	, 所以不管在那一家存放款, 都是一樣的. 錢莊的老闆是中原
	遷居到此的陳員外, 他的信用還不錯, 你可以看看這兒的公告
	(board),了解一下有甚麼服務.

LONG);

  set("exits", ([ /* sizeof() == 1 */
        "south" : __DIR__"road30",
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

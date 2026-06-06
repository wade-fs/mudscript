// made by funkcat, copy and re-edit by ccat
inherit BANK;
void create ()
{
	set("short","楓林錢莊");
  set ("long", @LONG
這裡是楓林錢莊 , 這邊的存款及放款量一向是全國數一數
二的 , 你可以看看這兒的公告(board),看看有甚麼服務.

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"p2-1.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "board" : "
    balance: 查看您現有的存款    convert: 換錢幣
    withdraw: 提款               deposit: 存款    
 ",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/officer" : 1,
]));

  setup();
}

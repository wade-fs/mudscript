// made by funkcat, copy and re-edit by WATARU
inherit BANK;
void create ()
{
set("short","殺手錢莊");
	set( "build", 8458 );
  set ("long", @LONG
這裡是殺手總壇的錢莊,這邊的存款額在全國是排行第一名,或許是殺手的賺錢方式不同
你可以安心的將錢存在這裡 . 這家錢莊的老闆是大財主諸岡渡，他是葉秀殺的客座軍師，
因此有不少人傳聞，這裡也是殺手支領完成任務的酬金處。
但是沒人能夠證實，因為暗殺工作沒人願意承認。
可以看看這兒的公告(board),看看有甚麼服務.

LONG);

  set("exits", ([ /* sizeof() == 1 */
"east" : __DIR__"ru1.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "board" : "
    balance: 查看您現有的存款    convert: 換錢幣
    withdraw: 提款               deposit: 存款    
 ",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
      "/open/killer/npc/wantman.c":1,
]));

  setup();
}

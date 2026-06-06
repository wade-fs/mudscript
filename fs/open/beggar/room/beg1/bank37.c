// Room: /u/g/guetenr/beggar/room/beg1/bank37.c
inherit BANK;

void create ()
{
  set ("short", "北庄財莊");
  set ("long", @LONG
屋內擺設著一整組的桌椅，皆是上等紫檀木整塊鏤空雕刻而成，看來氣
派非凡；椅上置軟墊，綾羅布面上繡著祥禽瑞獸富麗耀眼，兩側小几上植著
幾株金鐘花，枝條上布滿了花朵有如金泉噴湧，金碧輝煌的景象就像黃澄澄
的金子一般人見人愛呢；北邊有張櫃檯似的長桌，朝奉不時忙著將金子銀票
點收妥當。你可以在這邊存提(deposit/withdraw)錢喔!!
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"room28",
]));

  setup();
}

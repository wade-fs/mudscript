inherit ROOM;
void create()
{
  set ("short", "密室");
  set ("long", @LONG
這是東瀛機關聖手--諸岡渡，所建造的偉大密道。
這是因為有許多的門派令人看守大門,使得殺手們無法順利進行暗殺行動。
以至於當年黑牙連第一代掌門人葉孤城，遠赴東洋聘請諸岡渡。
並且於富士山上，取得了富士山密草。據說在總壇的某處有密草的存在。
小渡率領殺手們費了幾十年,來建造這個密道,
如今此密道已成,但你卻不知道他是要通往那裡!!
LONG);
   set("exits", ([
   "east"   : __DIR__"rbe.c",
   "west"   : __DIR__"rbw.c",
   "south"  : __DIR__"rbs.c",
   "north"  : __DIR__"rbn.c",
   "down"   : __DIR__"rbd.c",
  ]));
   set("no_fight", 1);
  set("no_magic", 1);
  set("no_transmit", 2);
  set("light_up", 1);
  setup();
} 

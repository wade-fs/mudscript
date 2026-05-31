inherit BULLETIN_BOARD;

void create()
{
	set_name("程式心得討論版", ({ "board" }) );
	set("location", "/open/wiz/program_room");
	set("board_id", "program_b");
	set("long",	"這是專門供給所有巫師討論程式與提供心得的板子\n");
	setup();
	set("capacity", 300);
}

inherit BULLETIN_BOARD;

void create()
{
     set_name("大紫檀木案",({"purple desk", "desk" , "board"}));
    set("location","/open/gblade/room/gblade");
    set("board_id","gblade");
    set("long", "案上有幾封各地傳來的信件，你不妨讀讀看。\n");
 setup();
 set("capacity", 50);
}

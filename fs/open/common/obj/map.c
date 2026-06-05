inherit BOOK;

#define BOOK_PATH "/open/center/obj/"
#define BOOK_NAME "map"
#define C_BOOK_NAME "主大陸地圖"

void create()
{
  ::create();
  set_name( C_BOOK_NAME, ({ "map" }) );
  set( "long", "這是一張由前輩高手冒險的心血所繪製的地圖。\n");
  
  // set ( "value", ({ 10, "silver" }) );
  set ( "book_path", BOOK_PATH + BOOK_NAME );
  setup();
}

void init()
{
  ::init();
}

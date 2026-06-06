inherit BOOK;

#define BOOK_PATH "/open/port/obj/"
#define BOOK_NAME "map"
#define C_BOOK_NAME "楓林港地圖"
				
void create()
{
  ::create();
  set_name( C_BOOK_NAME, ({ "map" }) );
	 set( "long", "這是一張官定的楓林港地圖 .\n");
  						
  set ( "book_path", BOOK_PATH + BOOK_NAME );
  setup();
}

void init()
{
  ::init();
}

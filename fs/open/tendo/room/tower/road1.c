
inherit ROOM;

void create()
{
  set ("short", "樹叢小徑");
  set ("long", @LONG
這是一條很不顯眼的小徑，叢生的雜草，以及蔽天的樹木，讓你很難分得
清楚方向。你注意到東邊隱隱約約有一座塔，你想你可以往那個方向找找。
LONG);

  set("outdoors", 1);
  setup();
}
void init() {
//   add_action("do_east","east");
   add_action("do_search","search");
}
/*
int do_east(string str) {
     if(!str){
        tell_object(this_player(),"你穿過樹叢～～\n");
        this_player()->move(__DIR__"road2");
        return 1;}
     else {
        tell_object(this_player(),"這個方向沒有出路。\n");
        return 1;}
}
*/

 int valid_leave( object who , string dir ) {
     if(dir == "east") { 
        tell_object(this_player(),"你穿過樹叢～～\n");
        this_player()->move(__DIR__"road2");
        return notify_fail("");
	}
     return ::valid_leave( who , dir );
}


int do_search(string str) {
     if(str == "east"){
        tell_object(this_player(),"你穿過樹叢～～\n");
        this_player()->move(__DIR__"road2");
        return 1;}
     else {
        tell_object(this_player(),"你似乎可以往東方找找看。\n");
        return 1;}
}



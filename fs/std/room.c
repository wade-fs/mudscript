// room.c
// add("clean_up",1) 先拿掉，因為就不用 clean_up 了 by whatup 2006/02/15
#pragma save_binary

#include <dbase.h>
#include <room.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

static mapping doors;

int query_max_encumbrance() { return 100000000000; }

private object make_inventory(string file)
{
	object ob;

	ob = new(file);
    if(!ob) return 0;
	ob->move(this_object());
	ob->set("startroom", base_name(this_object()));
	return ob;
}

void reset()
{
	mapping ob_list, ob;
	string *list;
	int i,j;

	//
	// Check loaded objects to match the objects specified in "objects"
	// while query("objects") is 
	// ([ <object filename>: <amount>, ..... ])
	// and query_temp("objects") is
	// ([ <object filename>: ({ob1, ob2, ...}), .... ])
	//
//應該要檢查一下是否有no_clean_up再設為0,不然就沒有不reborn的room了by bss
/*    if(!query("no_clean_up"))
    set("no_clean_up", 0);
//增加以下來作不會reborn的room,因為往下看都看不出來有做這樣的功能
    else    
    {*/
    if(query("no_clean_up"))
    if(query("have_reborn")) return ;
      set("have_reborn",1);
//    }
	ob_list = query("objects");
	if( !mapp(ob_list) ) return;
        if( query("no_reset") ) return;
//加了這行,若房間一開始就設no_reset,就跟本不會有object在房裡了!!
	
	if( !mapp(ob = query_temp("objects")) )
		ob = allocate_mapping(sizeof(ob_list));
	list = keys(ob_list);

	for(i=0; i<sizeof(list); i++) {
		// Allocate an array if we have multiple same object specified.
		if(	undefinedp(ob[list[i]])
		&&	intp(ob_list[list[i]])
		&&	ob_list[list[i]] > 1 )
			ob[list[i]] = allocate(ob_list[list[i]]);

		switch(ob_list[list[i]]) {
		case 1:
			if( !ob[list[i]] ) ob[list[i]] = make_inventory(list[i]);
           if(ob[list[i]])
			if( environment(ob[list[i]]) != this_object()
			&&	ob[list[i]]->is_character() ) {
				if( !ob[list[i]]->return_home(ob[list[i]]->query("startroom")) );
					//add("no_clean_up", 1);
					
				//if( !ob[list[i]]->move(ob[list[i]]->query("startroom")) )
				//	add("no_clean_up", 1);
			} 
        if( ob[list[i]] && environment(ob[list[i]]) != this_object() && !	ob[list[i]]->is_character() )
          ob[list[i]] = make_inventory(list[i]);

   
			break;
		default:
			for(j=0; j<ob_list[list[i]]; j++) {
				// If the object is gone, make another one.
				if( !objectp(ob[list[i]][j]) ) {
					ob[list[i]][j] = make_inventory(list[i]);
					continue;
				}
				// Try to call the wandering npc come back here.
				if( environment(ob[list[i]][j]) != this_object()
				&&	ob[list[i]][j]->is_character() ) {
					if( !ob[list[i]][j]->return_home(ob[list[i]][j]->query("startroom")) );
					
//						add("no_clean_up", 1);
					//if( !ob[list[i]][j]->move(ob[list[i]][j]->query("startroom")) )
						//add("no_clean_up", 1);
				}
        if( ob[list[i][j]] && environment(ob[list[i][j]]) != this_object() && !	ob[list[i][j]]->is_character() )

          ob[list[i][j]] = make_inventory(list[i]);


			}
		}
	}
	set_temp("objects", ob);
}

// Redirect item_desc of the door to this function in default.
string look_door(string dir, object ob)
{
	if( !mapp(doors) || undefinedp(doors[dir]) )
		return "你要看什麼﹖\n";
	if ( doors[dir]["status"] == DOOR_LOCKED )
		return "這個" + doors[dir]["name"] + "是鎖著的。\n";
	if( doors[dir]["status"] == DOOR_CLOSED )
		return "這個" + doors[dir]["name"] + "是關著的。\n";
	else
		return "這個" + doors[dir]["name"] + "是開著的。\n";
}

varargs int open_door(string dir, int from_other_side)
{
	mapping exits;
	object ob;

	if( !mapp(doors) || undefinedp(doors[dir]) )
		return notify_fail("這個方向沒有門。\n");

	if( (doors[dir]["status"] == DOOR_LOCKED) )
		return notify_fail( doors[dir]["name"] + "是鎖著的, 你必須先將它打開。\n");
	if( (doors[dir]["status"] != DOOR_CLOSED) )
		return notify_fail( doors[dir]["name"] + "已經是開著的了。\n");

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: open_door: attempt to open a door with out an exit.\n");

	if( from_other_side )
		message("vision", "有人從另一邊將" + doors[dir]["name"] + "打開了。\n", this_object());
	else if( objectp(ob = find_object(exits[dir])) ) {
		if( !ob->open_door(doors[dir]["other_side_dir"], 1) ) return 0;
	}

	doors[dir]["status"] = 0;
	return 1;
}

varargs int unlock_door(string dir, int from_other_side)
{
	mapping exits;
	object ob;

	if( !mapp(doors) || undefinedp(doors[dir]) )
		return notify_fail("這個方向沒有門。\n");

	if( !(doors[dir]["status"] & DOOR_LOCKED) ) {
		write ( doors[dir]["name"] + "並沒有鎖著。\n");
		return 0;
	}

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: unlock_door: attempt to open a door with out an exit.\n");

	if( from_other_side )
		message("vision", "喀的一聲, 有人從另一邊將" + doors[dir]["name"] + "的鎖打開了。\n", this_object());
	else if( objectp(ob = find_object(exits[dir])) ) {
		if ( !ob->unlock_door(doors[dir]["other_side_dir"], 1) )
                  return 0;
	}

	doors[dir]["status"] &= (!DOOR_LOCKED);
	doors[dir]["status"] |= (DOOR_CLOSED);
	return 1;
}

varargs int close_door(string dir, int from_other_side)
{
	mapping exits;
	object ob;

	if( !mapp(doors) || undefinedp(doors[dir]) )
		return notify_fail("這個方向沒有門。\n");

	if( (doors[dir]["status"] & DOOR_LOCKED) )
		return notify_fail( doors[dir]["name"] + "已經是鎖著的了。\n");
	else if( (doors[dir]["status"] & DOOR_CLOSED) )
		return notify_fail( doors[dir]["name"] + "已經是關著的了。\n");

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: close_door: attempt to open a door with out an exit.\n");

	if( from_other_side )
		message("vision", "有人從另一邊將" + doors[dir]["name"] + "關上了。\n", this_object());
	else if( objectp(ob = find_object(exits[dir])) ) {
		if( !ob->close_door(doors[dir]["other_side_dir"], 1) ) return 0;
	}

	doors[dir]["status"] |= DOOR_CLOSED;
	return 1;
}

varargs int lock_door(string dir, int from_other_side)
{
	mapping exits;
	object ob;

	if( !mapp(doors) || undefinedp(doors[dir]) )
		return notify_fail("這個方向沒有門。\n");

	if( (doors[dir]["status"] & DOOR_LOCKED) ) {
		write ( doors[dir]["name"] + "已經是鎖著的了。\n");
		return 0;
	}
	else if( !(doors[dir]["status"] & DOOR_CLOSED) ) {
		write ( doors[dir]["name"] + "是開著的, 必須先將它關上。\n");
		return 0;
	}

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: lock_door: attempt to open a door with out an exit.\n");

	if( from_other_side )
		message("vision", "喀的一聲, 有人從另一邊將" + doors[dir]["name"] + "鎖上了。\n", this_object());
	else if( objectp(ob = find_object(exits[dir])) ) {
		if ( !ob->lock_door(doors[dir]["other_side_dir"], 1) )
                  return 0;
	}

	doors[dir]["status"] &= !DOOR_CLOSED;
	doors[dir]["status"] |= DOOR_LOCKED;

	return 1;
}

int check_door(string dir, mapping door)
{
	// If we have no responding door, assume it is correct.
	if( !mapp(doors) || undefinedp(doors[dir]) ) return 1;

	door["status"] = doors[dir]["status"];
	return 1;
}

varargs void create_door(string dir, mixed data, string other_side_dir, int status)
{
	mapping d, exits, item_desc;
	object ob;

	exits = query("exits");
	if( !mapp(exits) || undefinedp(exits[dir]) )
		error("Room: create_door: attempt to create a door without exit.\n");

	// Compact mode.
	if( stringp(data) ) {
		d = allocate_mapping(4);
		d["name"] = data;
		d["id"] = ({ dir, data, "door" });
		d["other_side_dir"] = other_side_dir;
		d["status"] = status;
	} else if( mapp(data) )
		d = data;
	else
		error("Create_door: Invalid door data, string or mapping expected.\n");

	set("item_desc/" + dir, (: look_door, dir :) );

	if( objectp(ob = find_object(exits[dir])) ) {
		if( !ob->check_door(other_side_dir, d) )
			return;
	}

	if( !mapp(doors) ) doors = ([ dir: d ]);
	else doors[dir] = d;
}

mapping query_doors() { return doors; }

mixed query_door(string dir, string prop)
{
	if( !mapp(doors) || undefinedp(doors[dir]) ) return 0;
	else return doors[dir][prop];
}

int valid_leave(object me, string dir)
{
	if( mapp(doors) && !undefinedp(doors[dir]) ) {
		if( doors[dir]["status"] & DOOR_LOCKED )
			return notify_fail("你必須先把" + doors[dir]["name"] + "的鎖打開﹗\n");
                if (doors[dir]["status"] & DOOR_CLOSED )
			return notify_fail("你必須先把" + doors[dir]["name"] + "打開﹗\n");
		// if ( door[dir]["status"] & DOOR_HAS_TRAP ) ....
	}
	return 1;
}

void setup()
{
	seteuid(getuid());       
	// 如果沒有物件的話，就不用考慮重生了 by whatup 2006/02/15
	if(!query("objects") || query("no_reset") )
  	set_reset(this_object(),46800);
  else this_object()->reset();

}

string short()
{
  return query("short");
}

string long()
{
  return query("long");
}

// ── Compatibility for fsmud ported files ────────────────────────
void set_short(mixed s) { set("short", s); }
void set_long(mixed s)  { set("long", s); }
void add_exit(string dir, string path) { set("exits/" + dir, path); }
void set_coordinate(int x, int y, int z) { set("coordinate", ({ x, y, z })); }
void set_no_combat(int v) { set("no_combat", v); }
int query_is_lm_world() { return query("is_lm_world"); }

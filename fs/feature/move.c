// move.c

//#pragma optimize
#pragma save_binary

#include <dbase.h>
#include <type.h>
#include <ansi.h>
int my_weight = 0;
int encumb = 0;
int max_encumb = 0;

nomask int weight() { return my_weight + encumb; }
nomask int query_weight() { return my_weight; }
nomask int query_encumbrance() { return encumb; }
nomask int over_encumbranced() { return encumb > max_encumb; }
nomask int query_max_encumbrance() { return max_encumb; }
nomask void set_max_encumbrance(int e) { max_encumb = e; }

nomask void add_encumbrance(int w)
{
        encumb += w;
        if( encumb < 0 )
                log_file("move.bug", sprintf("%O encumbrance underflow.\n", this_object()));
        if( encumb > max_encumb ) this_object()->over_encumbrance();
        if( environment() ) environment()->add_encumbrance(w);
}

void over_encumbrance()
{
        if( !interactive(this_object()) ) return;
        tell_object(this_object(), "你的負荷過重了﹗\n");
}

nomask void set_weight(int w)
{
        if( !environment() ) {
                my_weight = w;
                return;
        }
        if( w!=my_weight ) environment()->add_encumbrance( w - my_weight );
        my_weight = w;
}

varargs int move(mixed dest, int silently)
{
        mixed err;
        object ob;
	
  if (query_temp("no_move"))
	  return notify_fail (stringp(query_temp("no_move") )? query_temp("no_move") : "你被限制不能移動，如果有問題，請告訴巫師..\n");

        // If we are equipped, unequip first.
        if( query("equipped") && !this_object()->unequip() )
                return notify_fail("你沒有辦法取下這樣東西。\n");
        // remove train force status
        if( userp(this_object()) && this_object()->query_condition("force") > 0 )
        {
  message_vision(
                HIW + "$N停止練功\，並且站了起來。\n" + NOR,this_object());

          this_object()->clear_condition("force");
        }
        if( userp(this_object()) && this_object()->query_condition("dhyana") > 0 )
        {
  message_vision(
                HIW + "$N停止參悟佛法，並且站了起來。\n" + NOR,this_object());

          this_object()->clear_condition("dhyana");
          if(present("prayer beads",this_object()))
            present("prayer beads",this_object())->change_color();
        }
        if( userp(this_object()) && this_object()->query_temp("NorthForceInUse") )
        {
  message_vision(
                HIW + "$N停止吸取天地靈氣，並且站了起來。\n" + NOR,this_object());

          this_object()->delete_temp("NorthForceInUse");
        }

        // Find the destination ob for moving.
        if(!dest) dest = environment(this_object());
        switch( typeof(dest) )
        {
                case "object" :
                        ob = dest;
                        break;
                case "string" :
                        if( err = catch(ob = load_object(dest) ) )
                                error( "move : error loading " + dest + ":\n" + err );
                        break;
                default :
												if(userp(this_object()))
													move_object(load_object("/open/common/room/inn.c"));
                        error( sprintf("move : Invalid destination. Expected: object or string, Got: %O \n %O \n %O \n", dest,call_stack(1),call_stack() ));
                        break;
        }

/*      下面這段在 call_other 那邊, 如果無法載入的話就話出錯
        改成上面的方式, 順便最佳化                              Arthur
        if( objectp(dest) )
                ob = dest;
        else if( stringp(dest) ) {
                call_other(dest, "???");
                ob = find_object(dest);
                if(!ob) return notify_fail("move: 目標房間不存在.\n");
        } else
                return notify_fail("move: 目標應該是房間的檔名.\n");
*/
        // Check if the destination ob can hold this object.
        if( (int)ob->query_encumbrance() + weight()
                > (int)ob->query_max_encumbrance() ) {
                if( ob==this_player() )
                        return notify_fail( this_object()->name() + "對你而言太重了。\n");
                else
                        return notify_fail( this_object()->name() + "對" + ob->name() + "而言太重了。\n");
        }

        // Move the object and update encumbrance
        if( environment() ) {
          environment()->add_encumbrance( - weight());
          this_object()->set("last_location", file_name(environment()));
        }
        move_object(ob);
        ob->add_encumbrance(weight());

        // If we are players, try look where we are.
        if( interactive(this_object())          // are we linkdead?
        &&      living(this_object()))          // are we still concious?
        {
                if (silently<=0)
                        command("look");
        }

        return 1;
}

void remove(string euid)
{
        object default_ob;

        if( !previous_object()
        ||      base_name(previous_object()) != SIMUL_EFUN_OB )
                error("move: remove() can only be called by destruct() simul efun.\n");

        if( userp(this_object()) && euid!=ROOT_UID ) {
                log_file("destruct", sprintf("%s attempt to destruct user object %s (%s)\n",
                        euid, this_object()->query("id"), ctime(time())));
                error("你(" + euid + ")不能摧毀其他的使用者。\n");
        } else if( this_object()->query("equipped")) {
                if(     !this_object()->unequip() )
                        log_file("destruct", sprintf("Failed to unequip %s when destructed.\n",file_name(this_object())));
        }

        // We only care about our own weight here, since remove() is called once
        // on each destruct(), so our inventory (encumbrance) will be counted as
        // well.
        if( environment() )     environment()->add_encumbrance( - my_weight );
/*        if( default_ob = this_object()->query_default_object() )
                default_ob->add("no_clean_up", -1);*/
}

int move_or_destruct( object dest )
{
        if( userp(this_object()) ) {
                tell_object(this_object(), "一陣時空的扭曲將你傳送到另一個地方....\n");
                move(VOID_OB);
        }
}

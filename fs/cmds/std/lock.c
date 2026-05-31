// lock.c

#include <room.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mapping doors;
	string *dirs, dir;
	string	key, *key_of_room;
	object ob, env;
	int i;

	if( !arg ) return notify_fail("你要鎖什麼﹖\n");
	arg = lower_case(arg);

	if (sscanf (arg, "%s with %s", arg, key) != 2) return
	  notify_fail ("你想用什麼鎖門啊。\n");
	if (!ob = present (key, me)) return
	  notify_fail ("你身上並沒有 "+key+"。\n");

	env = environment(me);
	doors = env->query_doors();
	if( mapp(doors) ) {
		dirs = keys(doors);
		if( member_array(arg, dirs)!=-1 ) dir = arg;
		else for(i=0; i<sizeof(dirs); i++)
			if( arg==doors[dirs[i]]["name"] || member_array(arg, doors[dirs[i]]["id"])!=-1 ) {
				dir = dirs[i];
				break;
			}
		if( !dir ) return notify_fail("你要鎖什麼﹖\n");
	
                if ((string)env->query("need_key/"+dir) ||
                    (string)env->query("need_key/door"))
                {
                  key_of_room=ob->query("key_of_room");
                  if (!sizeof (key_of_room) ||
                       strsrch(implode(key_of_room," "),file_name (env))==-1)
                  {
                      return notify_fail("這把鑰匙不能鎖這個門。\n");
                  }
                }

		if( env->lock_door(dir) ) {
		  message_vision("$N聽到喀的一聲, 將" + doors[dir]["name"] + "鎖上。\n", me);
		  return 1;
		}
	}

	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : lock <door> 或 <方向>
指令說明 : 
           這個指令可以讓你關上門.
其他參考 :
           unlock，open，close 
HELP
    );
    return 1;
}

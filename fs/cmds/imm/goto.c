// goto.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int goto_inventory = 0;
        object obj, env;
        string msg;

seteuid(getuid());
        if( !arg )
          if (me->query("last_location"))
	  {
          log_file("wiz/GOTO", sprintf("%s(%s) %s goto %s %s\n"
          ,me->query("name"),me->query("id"),file_name(environment(me)),me->query("last_location")
      ,ctime(time()) ));
            return me->move(me->query("last_location"));
	  }
          else
            return notify_fail("用法: goto [-i] 人|房間\n例如: goto wade 或 goto /u/w/wade/workroom\n");

        if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
        if (!obj) obj=LOGIN_D->find_body(arg);
if(!obj) obj = load_object(arg);
if(obj&&wizardp(obj)&&obj->query("env/隱身") && wiz_level(me) < wiz_level(obj))
           return notify_fail("沒有這個玩家、生物、或地方。1\n");
        if(!obj) {
                arg = resolve_path(me->query("cwd"), arg);
                if( !sscanf(arg, "%*s.c") ) arg += ".c";
                if( !(obj = find_object(arg)) ) {
                        if( file_size(arg)>0 ) {
/*              log_file("wiz/GOTO", sprintf("%s(%s) %s goto %s(%s) at %s %s\n"
            ,me->query("name"),me->query("id"),file_name(environment(me)),obj->query("name")
        ,obj->query("id"),arg,ctime(time()) ));*/
                          write("goto:"+arg+"\n");
                                return me->move(load_object(arg));
                        }
                        return notify_fail("沒有這個玩家、生物、或地方。\n");
                }
        }

        if(!goto_inventory && environment(obj))
                obj = environment(obj);

        if( !obj ) return notify_fail("這個物件沒有環境可以 goto。\n");

        if( stringp(msg = me->query("msg_mout")) )
                message_vision(msg, me);
        else
                message_vision("只見一陣煙霧過後﹐$N的身影已經不見了。\n", me);

        env = environment(me);
        log_file("wiz/GOTO", sprintf("%s(%s) %s goto %s %s\n"
        ,me->query("name"),me->query("id"),file_name(environment(me)),file_name(obj)
        ,ctime(time()) ));
        me->move(obj);
        if( !sizeof(all_inventory(env)) && ( !env->query("objects")
         || !sizeof(env->query("objects")) ) ) destruct(env);

        if( stringp(msg = me->query("msg_min")) )
                message_vision(msg, me);
        else
                message_vision("$N的身影突然出現在一陣煙霧之中。\n", me);

        return 1;
}

int help(object me)
{
write(@HELP
指令格式 : goto [-i] <目標>
 
這個指令會將你傳送到指定的目標. 目標可以是一個living 或房間
的檔名. 如果目標是living , 你會被移到跟那個人同樣的環境.
如果有加上 -i 參數且目標是 living, 則你會被移到該 living 的
的 inventory 中.
 
HELP
    );
    return 1;
}

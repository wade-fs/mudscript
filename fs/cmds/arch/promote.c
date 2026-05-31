// promote.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        string old_status, new_status, my_id;
        int my_level, ob_level, level;

        if( !arg || sscanf(arg, "%s %s", arg, new_status)!=2 )
                return notify_fail("指令格式﹕promote <使用者> <等級>\n");

        if( (level=SECURITY_D->query_valid_level(new_status))==-1 )
                return notify_fail("沒有這種等級。\n");

        ob = find_player(arg);
        if (!ob) {
          if (!ob = FINGER_D->acquire_login_ob(arg))
            return notify_fail ("沒有這個玩家。\n");
        }

        my_level = wiz_level(me);

        old_status = SECURITY_D->get_status(arg);
        ob_level = wiz_level(arg);

        my_id = me->query("id");
           if (my_id == arg)
                   return notify_fail("你不可以更改自己的等級。\n");
           if( (my_level <= ob_level && wizhood(me) != "(manager)" ) )
                   return notify_fail("你不能更動他的職位。\n");
// 加上一限制  By Swy
        if(my_level<SECURITY_D->query_valid_level(new_status))
        return notify_fail("你不能更動成比自己高的職位。\n");
        seteuid(getuid());

        if( !(SECURITY_D->set_status(me, arg, new_status)) )
                return notify_fail("修改失敗。\n");

        CHANNEL_D->do_channel( me, "sys",
          sprintf ("將%s(%s)的權限從%s改為%s。\n",
            ob->query("name"), arg, old_status, new_status));
        tell_object (ob, sprintf ("%s(%s)將你的等級變成%s\n",
                     me->name(), my_id, new_status));
       ob->save_autoload();
        ob->save();

        if( interactive(ob) ) {
          CHANNEL_D->do_channel( me, "sys", ob->short()+"離開這個世界了。\n");
          tell_object (ob, @LONG
    由於巫師涉及檔案存取權限問題，也牽涉到很多其他系統上的
未知情況太多，無法一一解決，暫時先以強迫你離開的方式解決，
請你 quit 之後再進來，再度進來時，你的等級已經改變了，如果
你是第一次當巫師，請你用 help wiz_init  查看你該做的事情。
LONG);
        }
        destruct (ob);

        return 1;
}

int help (object me)
{       
        write(@HELP
指令格式 : promote <玩家角色 ID> (<權限>)
指令說明 :
    這個指令可以修改玩家權限，目前權限定義在 /adm/daemons/securityd.c
    權限前後要用小括號括住，舉例如下
    promote wade (admin)

    如果真的不會設，或者低級無法設成高級，或者自己無法提昇自己的權限，
    又真的很想做，如果你能修改 /adm/etc/wizlist 這個檔，那可以先把 Mud
    暫時關閉(一定要關閉)，然後修改此檔，格式很簡單，
    wade (manager)
    wade (admin)
    這樣子重新開機之後就可以生效了。
HELP );
        return 1;
}


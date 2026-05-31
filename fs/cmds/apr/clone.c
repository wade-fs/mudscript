// clone.c

inherit F_CLEAN_UP;

int main(object me, string file)
{
        object obj;
        string err, msg, filename;

        seteuid( geteuid(me) );

        if (!file) file = me->query("cwf");
        if (!file)
                return notify_fail("你要複製什麼物件﹖\n");

        file = resolve_path(me->query("cwd"), file);
        if( sscanf(file, "%*s.c") != 1 ) file += ".c";
        me->set("cwf", file);

        if( file_size(file) < 0 )
                return notify_fail("沒有這個檔案(" + file + ")。\n");

        obj = find_object(file);

        if( !obj ) {
                err = catch(call_other(file, "???"));
                if (err) {
                        write("載入失敗﹕" + err + "\n");
                        return 1;
                }
        }
        else if (obj) destruct(obj);
        if (obj) return notify_fail ("你無法將這個物件摧毀。\n");

        err = catch(obj = new(file));
        if (err) {
                write("複製失敗﹕" + err + "\n");
                return 1;
        }

        if( !stringp(msg = me->query("msg_clone")) )
                msg = "只見$N伸手凌空一指﹐變出了$n。\n";
        else msg += "\n";       // 用 call 設定字串似乎無法換行....

        if( !obj->is_character() && obj->move(me) ) {
                write(obj->query("name") + "複製成功\﹐放在你的物品欄。\n");
                message_vision(msg, me, obj);
log_file("wiz/CLONE", sprintf("%s(%s) 複製%s(%s)放在身上%s\n"                                 
                ,me->query("name"),me->query("id"),obj->query("name"),file,ctime(time()) ));  
                return 1;
        }
        if( obj->move(environment(me)) ) {
                write(obj->query("name") + "複製成功\﹐放在這個房間。\n");
                message_vision(msg, me, obj);
                filename = base_name(environment(me)) + ".c";
log_file("wiz/CLONE", sprintf("%s(%s) 複製%s(%s)放在%s %s\n"
,me->query("name"),me->query("id"),obj->query("name"),file,filename,ctime(time()) ));
                return 1;
        }

        destruct(obj);
        return notify_fail("無法複製不能移動的物件(" + file + ")。\n");
}

int help(object me)
{
  write(@HELP
指令格式 : clone <檔名>

利用此指令可複製任何能移動之物件(含怪物)。
請配合 cd, dest 等使用。
HELP
    );
    return 1;
}

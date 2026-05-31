// dest.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string option, target;

	object obj;

	if (!arg) return notify_fail("指令格式 : dest <物件之名稱或檔名>\n" );

	if( sscanf(arg, "%s %s", option, target)!=2 ) target = arg;

	if( option == "-r" &&
		( (string)SECURITY_D->get_status(me)=="(admin)" ||
		  (string)SECURITY_D->get_status(me)=="(manager)" ))
	{
		seteuid(ROOT_UID);
	}
	obj = find_object(target);
	if (!obj) obj = present(target, me);
	if (!obj) obj = present(target, environment(me));
	if (!obj) obj = find_object( resolve_path(me->query("cwd"), target) );
	if (!obj) return notify_fail("沒有這樣物件....。\n");

	if( environment(me)==environment(obj) )
		message_vision("$N召喚出一個黑洞﹐嘗試將$n吞沒。\n", me, obj);

	if (userp(obj)) {
	  log_file("quit", 
                sprintf("%s於 %s 離開遊戲。", obj->short(), ctime(time()))
	  );
          CHANNEL_D->do_channel(me, "sys",
                sprintf("%s離開遊戲了。", obj->short()) );
	  obj->set("last_on", time());
	  obj->set("last_from", query_ip_name(obj));
	  obj->save();
	  destruct(obj);
	}
	else {
	  seteuid(geteuid(me));
	  destruct(obj);
	}
	if(obj) write("你無法將這個物件摧毀。\n");
	else write("哈哈哈, 好強的黑洞.\n");

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : dest [-r] <物件之名稱或檔名>

利用此一指令可將一個物件(object)或物件定義(class)從記憶體中清除﹐若清除物
件定義(即﹕指定檔名的情況下)則下一次參考到這個物件的時候會重新將它編譯。

具有 (admin) 以上身分的巫師可以用 -r 選項以 ROOT_UID 身分來清除被保護的物件如
使用者。

參考資料﹕ destruct(), clone
HELP
    );
    return 1;
}

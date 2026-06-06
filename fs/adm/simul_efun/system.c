// system.c

void shutdown(int code)
{
  object me = previous_object(1);
  object mob = previous_object(0);
  "/adm/daemons/scmd_d.c"->send_command("svn up");
  if( wiz_level(me) >= 5
  ||  strcmp(file_name(mob), "/obj/npc/demogorgon") != -1 )
    efun::shutdown(code);
}

/*
int save_object(string name, int flag)
{
  return 1;
}
*/

// ── Go-style String Utilities ──────────────────────────────
int str_has_prefix(string str, string prefix) {
    if (!str || !prefix) return 0;
    return strsrch(str, prefix) == 0;
}

int str_has_suffix(string str, string suffix) {
    int ls, lsu;
    if (!str || !suffix) return 0;
    ls = strlen(str);
    lsu = strlen(suffix);
    if (lsu > ls) return 0;
    return strsrch(str, suffix, -1) == (ls - lsu);
}

int str_contains(string str, string substr) {
    if (!str || !substr) return 0;
    return strsrch(str, substr) != -1;
}

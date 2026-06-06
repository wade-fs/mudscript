
string chinese_number(int i)
{
	return (string)CHINESE_D->chinese_number(i);
}

string to_chinese(string str)
{
	return (string)CHINESE_D->chinese(str);
}

int is_chinese(string str)
{
	if( strlen(str)>=2 && str[0] > 160 && str[0] < 255 ) return 1;
	return 0;
}

// ── 現代版相容性 Shim ─────────────────────────────────────
varargs string select_lang(mixed data, string lang) {
    if (stringp(data)) return data;
    if (mapp(data)) {
        if (!lang || lang == "") lang = "zh-TW"; // 預設繁中
        if (data[lang]) return data[lang];
        if (data["en"]) return data["en"];
        if (sizeof(data) > 0) return values(data)[0];
    }
    return "";
}

string _t(string str) {
    return str; // 簡易實作：直接回傳
}

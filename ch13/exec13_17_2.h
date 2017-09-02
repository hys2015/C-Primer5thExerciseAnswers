#pragma once
class numbered {
public:
	numbered() {
		++mysn;
	}
	numbered(numbered &n) {
		mysn = n.mysn + 1;
	}
	static int mysn;
};
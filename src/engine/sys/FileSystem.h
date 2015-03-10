#pragma once

namespace phantom {

	bool listFilesInDirectory(std::vector<String> &out, const String &path);

	// Wraps the basic fopen / fopen_s functions
	bool fileOpen(FILE **file, const String &fileName, const String &mode);
	void fileClose(FILE *file);

}

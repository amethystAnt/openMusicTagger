#ifndef TAGEDITORLAYOUT_H
#define TAGEDITORLAYOUT_H

#include <QtWidgets>
#include <asftag.h>
#include <id3v1tag.h>
#include <id3v2tag.h>
#include <apetag.h>
#include <infotag.h>
#include <xiphcomment.h>
#include <sstream>
#include "main.h"

class MainWindow;
class AudioFile;


/*
A class representing the layout of all tag editors for a file.
An object of this class is created in every file object.
It recognizes which tags are being in the file and generates tag
editors (objects of classes derived from the TagEditor class).
Once a file is selected to be edited, the dockable widget on the left is updated
and it sets the file's TagEditorLayout as the layout.
*/
class TagEditorLayout : public QVBoxLayout {
    Q_OBJECT

public:
    explicit TagEditorLayout(MainWindow* window, AudioFile *file);
    AudioFile* getFile();

private:
    MainWindow* window;
    AudioFile* file;
    void loadTagEditors();
    void loadAsfTags();
    void loadWavPackTags();
    void loadMpegTags();
    void loadFlacTags();
    void loadWavTags();
    void loadOggVorbisTags();
    TagLib::APE::Tag *apeTag;
    TagLib::ASF::Tag *asfTag;
    TagLib::ID3v1::Tag *id3v1Tag;
    TagLib::ID3v2::Tag *id3v2Tag;
    TagLib::RIFF::Info::Tag *infoTag;
    TagLib::Ogg::XiphComment *xiphComment;

public slots:
    void saveTags();

};

#endif // TAGEDITORLAYOUT_H

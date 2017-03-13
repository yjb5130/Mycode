#!/usr/bin/python
__metaclass__=type

import xml.dom.minidom

class Uiconfig:
    def __init__(self):
        self.doc = xml.dom.minidom.Document()
        #create UiNode
        self.Ui = self.doc.createElement('Ui')
        self.doc.appendChild(self.Ui)
        #create source Node
        self.sourceNode = self.doc.createElement('UinNode')
        self.sourceNode.setAttribute('attri', 'source')
        self.Ui.appendChild(self.sourceNode)

    def createSourceNode(self, order, name, show):
        #check param
        if not order.isdigit() :
            print 'Error value order:', order
            return
        if name.strip() == '' :
            print 'name is null'
            return
        if show != 'true' and show != 'false' : 
            print 'Error value show:', show
            return
        #create Item Node
        ItemNode = self.doc.createElement('Item')
        ItemNode.setAttribute('order', order)
        #create name Node
        nameNode = self.doc.createElement('name')
        nameNode.appendChild(self.doc.createTextNode(name))
        ItemNode.appendChild(nameNode)
        #create show Node
        showNode = self.doc.createElement('show')
        showNode.appendChild(self.doc.createTextNode(show))
        ItemNode.appendChild(showNode)
        self.sourceNode.appendChild(ItemNode)

    def exportXmlFile(self, xmlFileName):
        if xmlFileName.strip() == '' : print 'file name error'
        f = open(xmlFileName, 'w+');
        print self.doc.toprettyxml(encoding='utf-8')
        f.write(self.doc.toprettyxml(encoding='utf-8'))
        f.close()

uiconfig = Uiconfig()
uiconfig.createSourceNode('0', 'DTV',   'true')
uiconfig.createSourceNode('1', 'ATV',   'false')
uiconfig.createSourceNode('2', 'VGA',   'true')
uiconfig.createSourceNode('3', 'YPBPR', 'true')
uiconfig.createSourceNode('4', 'AV',    'true')
uiconfig.createSourceNode('5', 'AV1',   'false')
uiconfig.createSourceNode('6', 'AV2',   'false')
uiconfig.createSourceNode('7', 'HDMI1', 'true')
uiconfig.createSourceNode('8', 'HDMI2', 'true')
uiconfig.createSourceNode('9', 'HDMI3', 'true')
uiconfig.exportXmlFile('test.xml')


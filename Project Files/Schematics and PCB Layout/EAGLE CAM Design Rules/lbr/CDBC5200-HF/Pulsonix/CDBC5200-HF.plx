PULSONIX_LIBRARY_ASCII "SamacSys ECAD Model"
//2042959/1061851/2.49/2/3/Schottky Diode

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "r315_230"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 2.3) (shapeHeight 3.15))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(textStyleDef "Normal"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 1.27)
			(strokeWidth 0.127)
		)
	)
	(patternDef "DIOM8059X290N" (originalName "DIOM8059X290N")
		(multiLayer
			(pad (padNum 1) (padStyleRef r315_230) (pt -3.5, 0) (rotation 0))
			(pad (padNum 2) (padStyleRef r315_230) (pt 3.5, 0) (rotation 0))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 0, 0) (textStyleRef "Normal") (isVisible True))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -4.9 3.36) (pt 4.9 3.36) (width 0.05))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 4.9 3.36) (pt 4.9 -3.36) (width 0.05))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 4.9 -3.36) (pt -4.9 -3.36) (width 0.05))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -4.9 -3.36) (pt -4.9 3.36) (width 0.05))
		)
		(layerContents (layerNumRef 28)
			(line (pt -4 2.952) (pt 4 2.952) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 4 2.952) (pt 4 -2.952) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 4 -2.952) (pt -4 -2.952) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt -4 -2.952) (pt -4 2.952) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt -4 1.802) (pt -2.85 2.952) (width 0.025))
		)
		(layerContents (layerNumRef 18)
			(line (pt 4 2.952) (pt -4.65 2.952) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -4 -2.952) (pt 4 -2.952) (width 0.2))
		)
	)
	(symbolDef "CDBC5200-HF" (originalName "CDBC5200-HF")

		(pin (pinNum 1) (pt 100 mils 0 mils) (rotation 0) (pinLength 100 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 240 mils -15 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(pin (pinNum 2) (pt 700 mils 0 mils) (rotation 180) (pinLength 100 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 560 mils -15 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(line (pt 300 mils 100 mils) (pt 300 mils -100 mils) (width 6 mils))
		(line (pt 300 mils 100 mils) (pt 340 mils 100 mils) (width 6 mils))
		(line (pt 340 mils 100 mils) (pt 340 mils 60 mils) (width 6 mils))
		(line (pt 300 mils -100 mils) (pt 260 mils -100 mils) (width 6 mils))
		(line (pt 260 mils -100 mils) (pt 260 mils -60 mils) (width 6 mils))
		(line (pt 200 mils 0 mils) (pt 300 mils 0 mils) (width 6 mils))
		(line (pt 500 mils 0 mils) (pt 600 mils 0 mils) (width 6 mils))
		(poly (pt 300 mils 0 mils) (pt 500 mils 100 mils) (pt 500 mils -100 mils) (pt 300 mils 0 mils) (width 10  mils))
		(attr "RefDes" "RefDes" (pt 500 mils 350 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))
		(attr "Type" "Type" (pt 500 mils 250 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))

	)
	(compDef "CDBC5200-HF" (originalName "CDBC5200-HF") (compHeader (numPins 2) (numParts 1) (refDesPrefix D)
		)
		(compPin "1" (pinName "K") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(compPin "2" (pinName "A") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Bidirectional))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "CDBC5200-HF"))
		(attachedPattern (patternNum 1) (patternName "DIOM8059X290N")
			(numPads 2)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
			)
		)
		(attr "Mouser Part Number" "750-CDBC5200-HF")
		(attr "Mouser Price/Stock" "https://www.mouser.co.uk/ProductDetail/Comchip-Technology/CDBC5200-HF?qs=XEIV%2Fho1H6e7FEPE4wQmfQ%3D%3D")
		(attr "Manufacturer_Name" "Comchip Technology")
		(attr "Manufacturer_Part_Number" "CDBC5200-HF")
		(attr "Description" "Diode 200 V 5A Surface Mount DO-214AB (SMC)")
		(attr "<Hyperlink>" "https://www.comchiptech.com/admin/files/product/CDBC5150-HF%20Thru913202.%20CDBC5200-HF%20RevB.pdf")
		(attr "<Component Height>" "2.9")
		(attr "<STEP Filename>" "CDBC5200-HF.stp")
		(attr "<STEP Offsets>" "X=0;Y=0;Z=0")
		(attr "<STEP Rotation>" "X=0;Y=0;Z=0")
	)

)

package org.xtuml.bp.welcome.cheatsheets.library;
import org.eclipse.core.resources.IProject;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.jface.action.Action;
import org.eclipse.ui.cheatsheets.ICheatSheetAction;
import org.eclipse.ui.cheatsheets.ICheatSheetManager;
import org.xtuml.bp.core.Component_c;
import org.xtuml.bp.core.Package_c;
import org.xtuml.bp.core.PackageableElement_c;
import org.xtuml.bp.core.SystemModel_c;
import org.xtuml.bp.core.common.ClassQueryInterface_c;
import org.xtuml.bp.utilities.ui.CanvasUtilities;
import org.xtuml.bp.utilities.ui.ProjectUtilities;

public class OpenDiagramAction extends Action implements ICheatSheetAction{


	@Override
	public void run(String[] params, ICheatSheetManager manager) {
		String projectName = params[0];
		String elementType =   params [1]; 
		final String elementName = params[2];
		
		IProject project=null; 
        IProject[] projects = ResourcesPlugin.getWorkspace().getRoot().getProjects();
		for (int i = 0; i < projects.length; i++) {
			if(projects[i].getName().equalsIgnoreCase(projectName))
			{
				project = projects[i];
			}
		}		
		SystemModel_c systemModel = ProjectUtilities.getSystemModel(project);
		 
		
		if (elementType.equalsIgnoreCase("package"))
		{
		Package_c pckg = Package_c.getOneEP_PKGOnR1405(systemModel, new ClassQueryInterface_c() {
				
				@Override
				public boolean evaluate(Object candidate) {
				   Package_c selected = (Package_c)candidate;
					return selected.getName().equalsIgnoreCase(elementName);
				}
			});
			CanvasUtilities.openCanvasEditor(pckg);
		}
		else if (elementType.equalsIgnoreCase("component"))
		{
           Package_c[] pckgs = Package_c.getManyEP_PKGsOnR1405(systemModel);
           PackageableElement_c [] elems = PackageableElement_c.getManyPE_PEsOnR8000(pckgs);
           Component_c comp = Component_c.getOneC_COnR8001(elems, new ClassQueryInterface_c() {
				
				@Override
				public boolean evaluate(Object candidate) {
					Component_c selected = (Component_c)candidate;
					return selected.getName().equalsIgnoreCase(elementName);
				}
			});
           
           CanvasUtilities.openCanvasEditor(comp);
		}
		
		
	}
	

}
